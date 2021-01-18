# survive-time
## Join our discord server
[Survive-Time Discord Server](https://discord.gg/3vux22UJG5) <- click

[![sampctl](https://img.shields.io/badge/sampctl-survive--time-2f2f2f.svg?style=for-the-badge)](https://github.com/emmett-white/survive-time)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install emmett-white/survive-time
```

## Contributing & Style Guide
```c
// Constants and macros in uppercase, with underscores separating words.
// eg.
#define MAX_REASON_TEXT 64

const MAX_PLAYERS = 10;

// Variables
// Globals `static` as much as possible to prevent complex inter-module dependencies.
// eg.
static var1; // invalid
static var1,
    var2; // invalid

static
    var1,
    var2; // valid

// Brace style
// Allman
// eg.
func_name(const playerid, ...)
{
    if (...) {
        return ...;
    }

    if (...) {
        // code
        
        return ...;
    }
    
    return 1;
}

// Function names
// Functions and callbacks in lowercase
// eg.
get_player_level(const playerid)
{
    return char_score[playerid];
}

forward init_player_account(const playerid);
public init_player_account(const playerid)
{
    account_id[playerid] = cache_insert_id();
    return 1;
}
```

# survive-time
