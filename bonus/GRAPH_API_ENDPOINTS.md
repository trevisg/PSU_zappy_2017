# _ Zappy  **GraphClient to Server** protocol_

## Get game **map size**

-   Send `GET /mapsize`

-   Receive  `{ mapsize: {x: XX, y: XX} }`

## Get players **teams names**

-   Send `GET /teamnames`

-   Receive `{ teams: [XX,XX ...] }`

## Get a team **details**

-   Send `POST /team_detail&team=` + **[the team name]**

-   Receive `{ "teamname": { [id: xx, x: xx, y: xx, ttl: xx ], [..], [..] } }`
