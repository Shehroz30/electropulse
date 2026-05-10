
# Electropulse

A custom, homemade, low voltage, simple TENs device
![PCB](./imgs/refPic.png)

## Features
* ESP32-C3 Microntroller with Bluetooth
* Wireless control
* WiFi controlled
* USB-C powered
* Low-cost - total BOM + board ~$11.56 per board
* Two output channels
* Modular + fits with different electrode types
* Two buck boosts for efficiency
* BJT controlled current limiter

![PCB](./imgs/meddevelecrbg.png)

## Build
The build of this device is extremely uncomplicated. Use M3 0.5 inch screws for the enclosure and M2 0.315 inch screws for mounting the PCB. The electrodes can simply be attached to the Pin Headers.

A link to the Onshape file can be found [here](https://cad.onshape.com/documents/0b9b685ed737be4511598f4a/w/ba1d33f46afe7a8ff807ef53/e/736e59d6b3c7b8673a0b7fd8?renderMode=0&uiState=69ea24d6e717aaec3b4bf4c2)


## Use
* Flash the code onto the ESP32 using Arduino IDE
* Go to http://\<ESP-32\_IP\>/
* Connect your electrodes to the pin headers

## Motivation
I made this project because I've been struggling a little bit with knee pain and I found that other options on the market weren't as adjustable. I also had electrodes lying around (due to a separate business pitch project) and I wanted to make use of them

## BOM
To use this device, electrodes are a requirement. To purchase these, you can go to Amazon at [this link](https://www.amazon.com/Best-Sellers-Electrodes/zgbs/industrial/3013606011)
<img src="./imgs/electrodes.jpg" alt="Electrodes" width="200"/>


| Designator               | Footprint       |   Quantity | Value                | LCSC Part   | Link                                               |
|:-------------------------|:----------------|-----------:|:---------------------|:------------|:---------------------------------------------------|
| C1,C2,C3,C4              | 1206            |          8 | 4.7uF                | C29823      | https://www.lcsc.com/product-detail/C29823.html    |
| C5                       | 0603            |          2 | 0.047uF              | C1622       | https://www.lcsc.com/product-detail/C1622.html     |
| C8                       | 1206            |          2 | 10uF                 | C13585      | https://www.lcsc.com/product-detail/C13585.html    |
| C10,C11,C12,C13,C6,C7,C9 | 0603            |         18 | 0.1uF                | C14663      | https://www.lcsc.com/product-detail/C14663.html    |
| C18,C23                  | 0603            |        4   | 100nf                | C14663      | https://www.lcsc.com/product-detail/C14663.html    |
| C21,C22                  | 0605            |          4 | 10uf                 | C19702      | https://www.lcsc.com/product-detail/C19702.html    |
| C25,C26,C27              | 0805            |          6 | 22uf                 | C45783      | https://www.lcsc.com/product-detail/C45783.html    |
| D1                       | SMA(DO-214AC)   |          2 | D_Schottky           | C8678       | https://www.lcsc.com/product-detail/C8678.html     |
| D2                       | 0603            |          2 | LED                  | C2290       | https://www.lcsc.com/product-detail/C2290.html     |
| D4                       | SOT-23-6L       |          5 | USBLC6-2SC6          | C7519       | https://www.lcsc.com/product-detail/C7519.html     |
| J1                       | 插件,P=2.54mm     |          4 | Conn_01x02           | C32713268   | https://www.lcsc.com/product-detail/C32713268.html |
| J5                       | SMD             |          5 | MC-311D              | C136423     | https://www.lcsc.com/product-detail/C136423.html   |
| L1                       | 1008            |          5 | 2.2uH                | C86092      | https://www.lcsc.com/product-detail/C86092.html    |
| L2                       | SMD,7.2x6.6mm   |          5 | 10uH                 | C5189958    | https://www.lcsc.com/product-detail/C5189958.html  |
| Q2,Q4                    | SOT-23          |         10 | MMBT2222A            | C7420351    | https://www.lcsc.com/product-detail/C7420351.html  |
| Q3,Q5                    | SOT-223         |          5 | FZT853TA             | C435890     | https://www.lcsc.com/product-detail/C435890.html   |
| R1                       | 0603            |          2 | 250k                 | C22961      | https://www.lcsc.com/product-detail/C22961.html    |
| R2                       | 0603            |          2 | 330                  | C23138      | https://www.lcsc.com/product-detail/C23138.html    |
| R6                       | 0603            |          2 | 75k                  | C23242      | https://www.lcsc.com/product-detail/C23242.html    |
| R7                       | 0603            |          2 | 2k                   | C22975      | https://www.lcsc.com/product-detail/C22975.html    |
| R10,R14,R3               | 0603            |          6 | 10k                  | C25804      | https://www.lcsc.com/product-detail/C25804.html    |
| R11,R9                   | 0603            |          4 | 5.1k                 | C23186      | https://www.lcsc.com/product-detail/C23186.html    |
| R13,R19                  | 0603            |          4 | 14                   | C22950      | https://www.lcsc.com/product-detail/C22950.html    |
| R15                      | 0603            |          2 | 1M                   | C22935      | https://www.lcsc.com/product-detail/C22935.html    |
| R16                      | 0603            |         20 | 180k                 | C22827      | https://www.lcsc.com/product-detail/C22827.html    |
| R17,R18                  | 0603            |          4 | 1K                   | C21190      | https://www.lcsc.com/product-detail/C21190.html    |
| SW1,SW3                  | SMD,4x3mm       |          4 | TS-1088-AR02016      | C720477     | https://www.lcsc.com/product-detail/C720477.html   |
| U1                       | VFQFN-32-EP     |          2 | ESP32-C3-WROOM-02-N4 | C2934560    | https://www.lcsc.com/product-detail/C2934560.html  |
| U2                       | WQFN-16-EP(3x3) |          2 | TPS55340RTER         | C169167     | https://www.lcsc.com/product-detail/C169167.html   |
| U5                       | VSON-14-EP(3x4) |          2 | TPS63020DSJR         | C15483      | https://www.lcsc.com/product-detail/C15483.html    |

## JLCBPCB Order
For two assembled PCBs, the cost is around ~70$ for the cheapest shipping option. Keep in mind that there are a lot of alternatives to the parts selected, so ifsomething is unavailable you can easily change them around within the JLCPCB assembly order.
<img src = "./imgs/jlcpcborder.png" alt = "Order"/>

## Firmware

The code is written using Arduino IDE compiled for an ESP32-C3. Please note that the local host where the web page is hosted depends entirely on your ESP32, so it may not be the same for everyone. Also be sure to input your wifi credentials when flashing so that the ESP32 can connect to WiFi. 

## Fallout Zine Poster

<img src = "./imgs/zineposter.png" alt = "Zine Poster"/>

## Thanks

Huge thanks to HackClub for helping me with this project!


## Verfication
Hack Club Username: shehrozmaan4
