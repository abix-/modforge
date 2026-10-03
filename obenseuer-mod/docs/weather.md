# Weather

> **Authoritative on:** weather (Weather, WeatherManager). How weather
> follows indoor and outdoor areas is not researched yet (todo).
>
> Index of every game system's doc: [`research.md`](research.md).

## Weather

`Weather` is a ScriptableObject with weatherName, probability, duration
range, precipitation type (None, Snow, Rain), particle systems.
WeatherManager controls transitions; it is game-wide (in Game_Logic's
Globals, saves into Globals). Its events: WeatherUpdated,
WeatherTransitioning (WeatherManager.cs:74-76).
