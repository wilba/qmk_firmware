# wilba.tech WT80-H1

WT80-H1 is a keyboard PCB supporting TKL layout with 0.25U gaps. [More info at wilba.tech](https://wilba.tech/)

Keyboard Maintainer: [Wilba6582](https://github.com/Wilba6582)
Hardware Supported: wilba.tech WT80-H1
Hardware Availability: Custom keyboard group buys

Make example for this keyboard (after setting up your build environment):

    make wilba_tech/wt80_h1:default

Flashing example for this keyboard:

    make wilba_tech/wt80_h1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
