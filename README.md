
# Scopa – Qt Desktop Fork (designed around macOS)

This repository is a desktop-oriented fork of the original **Scopa** project
by Marco Scarpetta (2016).

The original project implements the Italian card game
[Scopa](https://en.wikipedia.org/wiki/Scopa) as a browser-based JavaScript
application, with an optional Qt wrapper for desktop use.

This fork focuses on improving desktop usability, modern macOS compatibility,
and adding persistent match tracking functionality.

---

## Origin

Original project:

- GNU Savannah project page:  
  https://savannah.gnu.org/projects/scopa/

- Original source repository:  
  git://git.git.savannah.gnu.org/scopa.git

All credit for the original implementation belongs to  
**Marco Scarpetta**.

This fork preserves the original licensing and attribution.

---

## Improvements in This Fork

### macOS Desktop Compatibility

- Fixed Linux-specific resource path assumptions
- Adjusted resource resolution for macOS `.app` bundle structure
- Verified compatibility with Apple Silicon (arm64)
- Improved startup behavior to avoid layout inconsistencies

### Layout Stability Fix

- Identified inconsistent card resizing caused by mixed initial/dynamic sizing logic
- Mitigated residual visual resizing bug by ensuring deterministic window initialization

### Persistent Match History

- Implemented match logging using `localStorage`
- Logs:
  - Timestamp
  - Winner
  - Final score
- Added in-app **Match History** menu item
- Displays last 10 matches in reverse chronological order
- Works in both Desktop Mode and Browser Mode

---

## Runtime Modes

This fork supports two ways of running the game.

---

### Desktop Mode (Qt)

Build the Qt application:

    make

On macOS, this generates a `.app` bundle inside:

    qt-application/scopa.app

You can launch it:

- From Finder (and it can be copied in the "Applications" folder) 
- Or via terminal:

    ./qt-application/scopa.app/Contents/MacOS/scopa

Desktop mode uses Qt WebEngine (embedded Chromium).

Tested primarily on:

- macOS (Apple Silicon, Qt 5.15)

> Linux desktop builds have not been fully revalidated after macOS-specific adjustments.

---

### Forcing the UI language

You can override the language when launching the application:

```bash
./scopa.app/Contents/MacOS/scopa --lang=it
```

This relies on Qt WebEngine's --lang flag and overrides the default system language detection.

---

### Browser Mode (Cross-Platform)

The core game is a static HTML + JavaScript application.

It can be run on any OS (macOS, Linux, Windows) using a local web server.

From the project root:

    python3 -m http.server 8000

Then open:

    http://localhost:8000

Browser mode:

- Does not require Qt
- Remains cross-platform
- Includes match history functionality

---

## Technical Notes

### Resource Path Adjustments

The original Qt wrapper assumed a Linux installation layout:

    /usr/bin/scopa
    /usr/share/scopa/index.html

This fork adjusts resource loading to work correctly inside the macOS
`.app` bundle structure:

    scopa.app/Contents/MacOS/

---

### Match Logging Implementation

Match logging is implemented entirely in JavaScript.

When a match ends:

- The `"winner"` event is detected
- The final score is extracted from the summary table
- A structured entry is appended to:

    localStorage["matchLog"]

Each entry includes:

- ISO timestamp
- Winner name
- Final score

Storage size remains small and practical even after hundreds of matches.

---

## Purpose of This Fork

This fork was created to:

- Improve desktop reliability on macOS
- Explore cross-platform debugging in a mixed C++ / JavaScript environment
- Enhance user experience with persistent match tracking
- Maintain compatibility with the original browser-based architecture

It preserves the spirit and functionality of the original project
while improving desktop usability.

---

## License

This fork remains licensed under the  
**GNU General Public License v3.0**,  
in accordance with the original project.

See the `LICENSE` file for full details.
