# GRAPHClient to Server (JSON Restfull-API)
---------

|            Request           |      Response         | Curl example|
| :--------------------------: | :-------------------: | :--------: |
| `GET /mapsize`               | `{"mapsize": {"x": XX, "y": XX}}\n`| `curl -s -X GET http://127.0.0.1:2222/mapsize` |
| `GET /teamnames` | `{ "teams": ["XX","XX",..]}\n` | `curl -s -X GET http://127.0.0.1:2222/teamnames` |
| `POST /team_detail&team=XX` | `{ "XX": [{"id": xx, "x": xx, "y": xx, "ttl": xx }, {...}]}` |`curl -s -X POST http://127.0.0.1:2222/team_detail&team=XX`



## Get game **map size**

-   Send `GET /mapsize`

-   Receive  `{ mapsize: {x: XX, y: XX} }`

-   With curl : `curl -s -X GET http://127.0.0.1:2222/mapsize`

## Get players **teams names**

-   Send `GET /teamnames`

-   Receive `{ teams: [XX,XX ...] }`

-   With curl : `curl -s -X GET http://127.0.0.1:2222/teamnames`

## Get a team **details**

-   Send `POST /team_detail&team=` + **[the team name]**

-   Receive `{ "teamname": { [id: xx, x: xx, y: xx, ttl: xx ], [..], [..] } }`

-   With curl : `curl -s -X POST http://127.0.0.1:2222/team_detail&team=XX`

-   Note : *(replace XX with a real team name)*
