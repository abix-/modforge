// Address: 0x14027fba0
// Ghidra name: FUN_14027fba0
// ============ 0x14027fba0 FUN_14027fba0 (size=482) ============


void FUN_14027fba0(longlong param_1)



{

  short sVar1;

  int iVar2;

  undefined1 *puVar3;

  char *pcVar4;

  int iVar5;

  undefined1 local_68 [32];

  undefined1 local_48 [5];

  undefined1 local_43;

  undefined1 local_42;

  undefined1 local_41;

  undefined1 local_40;

  undefined1 local_3f;

  char local_3e;

  char local_3b;

  

  puVar3 = (undefined1 *)FUN_1401841a0(1,0x78);

  if (puVar3 == (undefined1 *)0x0) {

    return;

  }

  iVar5 = 0;

  *(undefined1 **)(param_1 + 0x70) = puVar3;

  if (*(short *)(param_1 + 0x22) == 0x6012) {

    do {

      iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x50);

      if (iVar2 != 0) {

        if (0x21 < iVar2) {

          *puVar3 = 1;

          puVar3[4] = 1;

          puVar3[8] = 1;

        }

        break;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < 3);

  }

  else {

    do {

      iVar2 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),6,local_48,0x40);

      if (0 < iVar2) {

        *puVar3 = 1;

        puVar3[4] = 1;

        puVar3[8] = 1;

        if (iVar2 < 0xe) {

          if (iVar2 < 0xc) break;

        }

        else if (local_3b == -0x56) {

          puVar3[9] = 1;

        }

        if (local_3e != '\0') {

          FUN_14012ef10(local_68,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",local_3e,local_3f,local_40,

                        local_41,local_42,local_43);

          FUN_140208490(param_1,local_68);

        }

        break;

      }

      FUN_1401492f0(10);

      iVar5 = iVar5 + 1;

    } while (iVar5 < 5);

  }

  sVar1 = *(short *)(param_1 + 0x22);

  if ((sVar1 == 0x6000) || (sVar1 == 0x6100)) {

    pcVar4 = "8BitDo SF30 Pro";

  }

  else if ((sVar1 + 0x9fffU & 0xfeff) == 0) {

    pcVar4 = "8BitDo SN30 Pro";

  }

  else if ((sVar1 == 0x6003) || (sVar1 == 0x6006)) {

    pcVar4 = "8BitDo Pro 2";

  }

  else {

    if (sVar1 != 0x6009) goto LAB_14027fd71;

    pcVar4 = "8BitDo Pro 3";

  }

  FUN_1402083c0(param_1,pcVar4);

LAB_14027fd71:

  FUN_140208110(param_1,0);

  return;

}




