// Address: 0x1402888c0
// Ghidra name: FUN_1402888c0
// ============ 0x1402888c0 FUN_1402888c0 (size=233) ============


undefined8 FUN_1402888c0(longlong param_1,char *param_2,int param_3)



{

  char cVar1;

  undefined4 *puVar2;

  undefined8 uVar3;

  

  if (param_3 == 0) {

    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;

    *(undefined8 *)(param_1 + 0x28) = 0;

    return 1;

  }

  puVar2 = (undefined4 *)FUN_1401841f0((longlong)param_3 << 2);

  if (puVar2 != (undefined4 *)0x0) {

    FUN_1402f94c0(puVar2,0,(longlong)param_3 << 2);

    *(undefined4 **)(param_1 + 0x28) = puVar2;

    cVar1 = *param_2;

    if (cVar1 == '\0') {

      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x20;

      *puVar2 = *(undefined4 *)(param_2 + 4);

    }

    else {

      if (cVar1 == '\x01') {

        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;

      }

      else {

        if (cVar1 != '\x02') {

          if (cVar1 == '\x03') {

            *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;

            *puVar2 = 0;

            return 1;

          }

          uVar3 = FUN_14012e850("Haptic: Unknown direction type.");

          return uVar3;

        }

        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;

      }

      *puVar2 = *(undefined4 *)(param_2 + 4);

      if (1 < param_3) {

        puVar2[1] = *(undefined4 *)(param_2 + 8);

      }

      if (2 < param_3) {

        puVar2[2] = *(undefined4 *)(param_2 + 0xc);

      }

    }

    return 1;

  }

  return 0;

}




