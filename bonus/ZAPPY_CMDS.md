# Zappy AIClient to Server protocol

|            Actions           |      Command     | Time limit |                    Response                   |
| :--------------------------: | :--------------: | :--------: | :-------------------------------------------: |
|        Move up on tile       |     `Forward`    |     7/f    |                       ok                      |
|        Turn 90° right        |      `Right`     |     7/f    |                       ok                      |
|         Turn 90° left        |      `Left`      |     7/f    |                       ok                      |
|          Look around         |      `Look`      |     7/f    |                [tile1,tile2...]               |
|           Inventory          |    `Inventory`   |     1/f    |           \[linemate _n_, sibur _n_]          |
|        Broadcast text        | [Broadcast text] |     7/f    |                       ok                      |
|  Number of team unused slot  |   `Connect_nbr`  |      -     |                     value                     |
|         Fork a player        |      `Fork`      |    42/f    |                       ok                      |
| Eject players from this tile |      `Eject`     |     7/f    |                     ok/ko                     |
|       Death of a player      |         -        |      -     |                      dead                     |
|          Take object         |   `Take object`  |     7/f    |                     ok/ko                     |
|        Set object down       |   `Set object`   |     7/f    |                     ok/ko                     |
|       Start incantation      |   `Incantation`  |    300/f   | Elevation underway'\\n'Current level: _k_ /ko |

### Requirements

-   All commands are transmitted through a character string that ends with a new line.
-   The client can send up to 10 requests in a row without any response from the server.
    Over 10, the server will no longer take them into account.
