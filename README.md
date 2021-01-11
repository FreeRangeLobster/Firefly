I am an aquarist enthusiast; I have a fully automated fish tank at home.
When my daughter Sofia was born two years ago, I couldn’t really dedicate as much spare time to my fish tank, and was spending it with her instead. She is very curious, and she found the fish tank buttons and indicators very attractive. She was always fiddling with them, pressing them, and enjoyed when the buttons would illuminate – to the point where I had to disable the button internal functionalities, as the poor fish would suffer from a stroboscopic effect otherwise. Cool in a party not cool in a tank
This is when I had an idea: what if I built an interactive table for Sofia, so she has her own buttons to play with (and leave the poor fish alone)? And that’s exactly what I did.
Over the past few weeks I spent some lunch times and evenings designing, building and programming a child friendly interactive table. This is what I did:

-          The first step was to find a controller with many IO, which should also be able to control addressable LEDs. After some research, I concluded that my weapon of choice will be an ESP-32.

-          The next task was to design the table and order all the components. My colleagues in the machine shop helped me manufacture the base plate. Note that I upcycled a small sand&water play table, so I only needed to design and manufacture the base to fit on top of it.

-          When the components arrived and the Perspex base was ready, I wired it all up. This only took a couple of days.

-          Then the programming started. Fortunately, there is a big community of open software/hardware and a lot of the libraries are already available, which helped me a lot.

On 20th December the system was ready for the tester (my daughter). She enjoyed it a lot and so far the table seems to be withstanding the abuse it’s getting.
I am not quite yet finished with the work. I would still like to add some sounds to it, and perhaps add IOT capabilities and connecting the table to Alexa – “Alexa, red lights please!”
So far we are all happy. Sofia has a custom-made interactive table, I learned something new, and the fish are finally enjoying some quiet time in their tank. This is only one small application aiming to encourage my daughter into STEM, it is never too early!





# TheCloud
Table with buttons and lights

#TheLight
Inputs
5 buttons
GPIO18
GPIO2
GPIO15
GPIO0

4 Joystick
GPIO36
GPIO39
GPIO34
GPIO35

5 Outputs
GPIO23
GPIO22
GPIO1
GPIO3
GPIO21

CAN
GPIO4 RX
GPIO5 TX

Connect 3V to power the buttons
Test the LEDs of the buttons

40*59*35


Priority Pins
gpio4
gpio5
gpio16
gpio17
gpio18
gpio19
gpio23
gpio25
gpio26
gpio27
gpio32
gpio33