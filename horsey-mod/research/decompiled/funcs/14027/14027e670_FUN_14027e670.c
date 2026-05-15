// Address: 0x14027e670
// Ghidra name: FUN_14027e670
// ============ 0x14027e670 FUN_14027e670 (size=205) ============


ulonglong FUN_14027e670(longlong param_1)



{

  undefined1 uVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  

  puVar2 = (undefined8 *)FUN_1401841f0(0x24);

  if (puVar2 == (undefined8 *)0x0) {

    uVar3 = FUN_14012e770();

  }

  else {

    *puVar2 = 0;

    puVar2[1] = 0;

    puVar2[2] = 0;

    puVar2[3] = 0;

    *(undefined4 *)(puVar2 + 4) = 0;

    *(undefined8 **)(param_1 + 0x70) = puVar2;

    *(undefined4 *)(param_1 + 0x58) = 2;

    uVar4 = FUN_14027ead0(*(undefined2 *)(param_1 + 0x22));

    FUN_1402083c0(param_1,uVar4);

    uVar3 = FUN_140193900(*(undefined8 *)(param_1 + 0x80),1);

    if ((int)uVar3 == 0) {

      uVar3 = FUN_14027f5a0(param_1,0);

      if ((char)uVar3 != '\0') {

        if (((*(short *)(param_1 + 0x22) == -0x3d6c) &&

            ((*(ushort *)(param_1 + 0x24) & 0xff00) == 0x2100)) &&

           ((char)*(ushort *)(param_1 + 0x24) == '\0')) {

          uVar1 = 1;

        }

        else {

          uVar1 = 0;

        }

        *(undefined1 *)((longlong)puVar2 + 0x21) = uVar1;

        *(undefined2 *)((longlong)puVar2 + 0x22) = 900;

        uVar3 = FUN_140208110(param_1,0);

        return uVar3;

      }

    }

  }

  return uVar3 & 0xffffffffffffff00;

}




