# BrokenIRC rev 0.43 RFC Write Up

## Current version [#QuickAndDirty](https://github.com/trevisg/PSU_myirc_2017BrokenStuffisBack/releases/tag/vQuickAndDirty)

This is (supposed to be) an EPITECH BrokenIRC Protocol RFC's [2812](https://tools.ietf.org/html/rfc2812) & oldest [1459](https://tools.ietf.org/html/rfc1459)
compliant IRCd C server

##### From Subject :
> You **MUST** not use thread(), fork() & fcntl() kind off functions
> =>> Tss easy [epoll control](man7.org/linux/man-pages/man2/epoll_ctl.2.html) ..

### 1. IRC commands from client to server:

| CMD	| USAGE				| Description			|
|-------|:-----------------------------:|------------------------------:|
| USER	| `USER <SP> <username> <CRLF>` | Specify user for authentication |


### 2. Command-Reply Sequences (Mandatory part)

>The server reply is defined to contain the 3-digit code, followed by space
> **< SP >** , followed by one line of text, and terminated by the Irc end-of-line code **< CRLF >** (aka ```\r\n```).

### 3. Example :

```
-> NICK <SP> Nickname <CRLF>
-> USER <SP> Username <CRLF>
<- 331 <SP> User name okay, need password. <CRLF>
-> PASS <SP> Password <CRLF>
<- 230 <SP> User logged in, proceed. <CRLF>
```
> **->** : Request command from client to server

> **<-** : Reply from server to client

            Connection Establishment


            Registration
               USER ->
                  <- 230
                  <- xxx
                  <- 331
               PASS ->
                  <- 230
                  <- 332
                  <- xxx
               CWD ->
                  <- 250
                  <- xxx
               CDUP ->
                  <- 200
                  <- xxx

            Logout
               QUIT ->
                  <- 221
                  <- xxx

### 5. Numeric  Order List of Mandatory Reply Codes (Extract)

| Code	  | Description							|
|:-------:|:-----------------------------------------------------------:|
|   001   | The very first response from server				|
