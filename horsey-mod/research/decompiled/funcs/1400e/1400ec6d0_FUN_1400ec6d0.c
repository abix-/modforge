// Address: 0x1400ec6d0
// Ghidra name: FUN_1400ec6d0
// ============ 0x1400ec6d0 FUN_1400ec6d0 (size=214) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ec6d0(longlong param_1,uint param_2,longlong param_3)



{

  int iVar1;

  undefined1 *puVar2;

  undefined1 uVar3;

  uint uVar4;

  longlong lVar5;

  

  uVar4 = 0x80;

  lVar5 = 0;

  do {

    if ((param_2 & uVar4) != 0) {

      if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ec718:

        if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8)) {

LAB_1400ec794:

          _DAT_1403f4c40 = "bad file";

          return 0;

        }

        puVar2 = *(undefined1 **)(param_1 + 0xb8);

LAB_1400ec736:

        uVar3 = *puVar2;

        *(undefined1 **)(param_1 + 0xb8) = puVar2 + 1;

      }

      else {

        iVar1 = (**(code **)(param_1 + 0x20))();

        if (iVar1 != 0) {

          if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400ec794;

          goto LAB_1400ec718;

        }

        puVar2 = *(undefined1 **)(param_1 + 0xb8);

        if (puVar2 < *(undefined1 **)(param_1 + 0xc0)) goto LAB_1400ec736;

        if (*(int *)(param_1 + 0x30) != 0) {

          FUN_1400ed820(param_1);

          puVar2 = *(undefined1 **)(param_1 + 0xb8);

          goto LAB_1400ec736;

        }

        uVar3 = 0;

      }

      *(undefined1 *)(lVar5 + param_3) = uVar3;

    }

    lVar5 = lVar5 + 1;

    uVar4 = (int)uVar4 >> 1;

    if (3 < lVar5) {

      return param_3;

    }

  } while( true );

}




