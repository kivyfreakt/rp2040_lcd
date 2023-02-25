# RP2040 tests

## Information:
for use with WAVESHARE RP2040-LCD-1.28

## Basic use:
1. You need to execute:
    If the directory already exists, you can go directly. If there is no build directory, execute

```bash
mkdir build
```

2. Enter the build directory and type in the terminal:

```bash
cd build
export PICO_SDK_PATH=<pico sdk path>
```

3. Execute cmake, automatically generate Makefile file, enter in the terminal:

```bash
cmake ..
```

4. Execute make to generate an executable file, and enter in the terminal:

```bash
make
```

5. Copy the compiled uf2 file to pico

## Pin connection:
- I2C_SDA -> 6
- I2C_SDA -> 7
- DC -> 8
- CS -> 9
- SCK -> 10
- DIN -> 11
- RST -> 12  
- BL -> 25
- BAT_ADC -> 29
