# NewAngle keyboard

This is my solution for a portable, ergonomic keyboard.

It has 37 keys yet includes features like mousekeys and the ability to hit "F14-Super-Alt-Control" without moving one's fingers very far from their home keys. It does this by overloading the thumbs, which are my strongest and nearly my most dextrous phalanges yet which are barely used with a normal keyboard. I built mine with Cherry ML switches.

The name "NewAngle" reflects three things: my inability to come up with good names, the angular ergonomics, and that I haven't seen these concepts combined like this before. The layout (and camelCase name) borrows heavy from concepts developed by the ErgoDox and TextBlade. The ErgoDox has a nice thumb cluster, which becomes a game-changer when combined with the function layers enabled by the TMK and QMK firmware. The TextBlade shows that a compact board can still do a lot of things, if the user is willing to re-train their muscle memory a bit.

The most novel design here, though, is something I stole from the QWERY layout: staggered rows. Except, with NewAngle, they are symmetrical. Then, I dropped the home key of the index finger to the row below the I-M-A fingers. (Try this experiment: with your right hand, place your middle through pinky fingers on their home keys, K-L-;. Now, place your index finger on the M key. Isn't that more comfortable than the J key? Now, lift each finger to the row above its home key, then drop it to the key below the home key. The home row should be M-K-L-; on the right.)

The layout started with a Dvorak pattern. The key layout, however, required some things to move, so many things ended up moving. The current design was chosen for text input, but I've been coding for a few months and it works just fine for that, too.

These files would be droppped in the QMK or TMK firmware source directory under keyboards/newangle. Other files are, I believe, unchanged from the default new keyboard templates.
- keymaps/default/keymap.c contains the key mapping
- config.h adds a macro definition for USB_POWER_MAX_CONSUMPTION that allows the Teensy-2.0-based keyboard to work on iOS devices (this might be lying to the device, which is never a good idea, but it works so I'm doing it anyway)
- newangle.h defines the keyswitch matrix, enabling the firmware to properly interpret the key map

I'm happy to share my PCB layout files, too, if anyone's interested.
