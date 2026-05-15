// Address: 0x14026e6f0
// Ghidra name: FUN_14026e6f0
// ============ 0x14026e6f0 FUN_14026e6f0 (size=270) ============


void FUN_14026e6f0(longlong param_1)



{

  short sVar1;

  ushort uVar2;

  longlong *plVar3;

  undefined1 uVar4;

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x60);

  if (plVar3 == (longlong *)0x0) {

    return;

  }

  *plVar3 = param_1;

  if ((*(short *)(param_1 + 0x20) == 0x2563) && (*(short *)(param_1 + 0x22) == 0x575)) {

    uVar4 = 0;

  }

  else {

    uVar4 = 1;

  }

  *(undefined1 *)((longlong)plVar3 + 0x11) = uVar4;

  *(longlong **)(param_1 + 0x70) = plVar3;

  *(undefined4 *)(param_1 + 0x5c) = 4;

  if ((*(short *)(param_1 + 0x20) == 0x46d) && (*(short *)(param_1 + 0x22) == -0x352f)) {

    FUN_1402083c0(param_1,"Logitech ChillStream");

  }

  if (*(short *)(param_1 + 0x20) == 0x1bad) {

    sVar1 = *(short *)(param_1 + 0x22);

    if (sVar1 == 4) {

LAB_14026e7f5:

      *(undefined4 *)(param_1 + 0x58) = 6;

      goto LAB_14026e7a2;

    }

    if (sVar1 != 5) {

      if (sVar1 == 0x3010) goto LAB_14026e7f5;

      if ((sVar1 != 0x3110) && (sVar1 != 0x3138)) goto LAB_14026e7a2;

    }

  }

  else {

    if (*(short *)(param_1 + 0x20) != 0x12ba) goto LAB_14026e7a2;

    uVar2 = *(ushort *)(param_1 + 0x22);

    if (uVar2 < 0x211) {

      if (uVar2 != 0x210) {

        if (uVar2 != 0x100) {

          if (uVar2 == 0x120) goto LAB_14026e79b;

          if (uVar2 != 0x200) goto LAB_14026e7a2;

        }

        goto LAB_14026e7f5;

      }

    }

    else if (uVar2 != 0x218) {

      if (uVar2 != 0x74b) goto LAB_14026e7a2;

      goto LAB_14026e7f5;

    }

  }

LAB_14026e79b:

  *(undefined4 *)(param_1 + 0x58) = 7;

LAB_14026e7a2:

  FUN_140208110(param_1,0);

  return;

}




