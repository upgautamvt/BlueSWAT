# BlueSWAT: A Lightweight State-Aware Security Framework for Bluetooth Low Energy

## 3. Memory consumption

When no rules are loaded, the compiler outputs the following results:

```
[234/239] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:      204859 B         1 MB     19.54%
            SRAM:       45184 B       256 KB     17.24%
        IDT_LIST:         136 B         2 KB      6.64%
[239/239] Linking C executable zephyr/zephyr.elf
```

When 10 rules are loaded, the results are:

```
[234/239] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:      206159 B         1 MB     19.66%
            SRAM:       45344 B       256 KB     17.30%
        IDT_LIST:         136 B         2 KB      6.64%
[239/239] Linking C executable zephyr/zephyr.elf
```

## 5. Power assess

We access the power and energy performance of BlueSWAT over a 120-second window, encompassing four phases: 20s of connection, 40s of BAS, another 20s of connection, and 40s of HRS.

Since power assess requires a ChargerLAB POWER-Z KT002 and it is not available for reviewers, we provide the original monitor result of baseline and BlueSWAT in *baseline.csv* and *blueswat.csv*.