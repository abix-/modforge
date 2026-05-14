// Address: 0x14002cfc0
// Ghidra name: FUN_14002cfc0
// ============ 0x14002cfc0 FUN_14002cfc0 (size=407) ============


undefined8 FUN_14002cfc0(longlong param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  float local_res8 [2];

  char local_28 [4];

  char local_24 [2];

  char local_22;

  undefined1 local_21;

  undefined8 local_20;

  undefined8 local_18;

  undefined8 local_10;

  

  if (*(int *)(param_1 + 0x250) == 0) {

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

    cVar2 = FUN_1400b7660(lVar1,0,0);

    if (cVar2 != '\0') {

      FUN_1400b4a10(lVar1,local_res8);

      if (DAT_14039ca58 < local_res8[0]) {

        cVar2 = FUN_1400c5740(local_res8,*(undefined8 *)(param_1 + 0x78),0);

        if (cVar2 == '\0') {

          FUN_1400b6610(lVar1,lVar1 + 0x1d4);

        }

        *(undefined4 *)(lVar1 + 0x228) = 0xffffffff;

        *(undefined4 *)(lVar1 + 0x224) = 0;

        return 1;

      }

      *(undefined1 *)(lVar1 + 0x1a) = 0;

      uVar4 = FUN_1400b6170(lVar1);

      FUN_1400b6820(lVar1,DAT_1403033a0,uVar4);

      if (*(int *)(lVar1 + 0x224) == 0) {

        *(undefined4 *)(lVar1 + 0x224) = *(undefined4 *)(param_1 + 0x284);

        *(int *)(lVar1 + 0x228) = *(int *)(param_1 + 0x284) + -1;

        *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;

        if (0x10 < *(int *)(param_1 + 0x284)) {

          *(undefined4 *)(param_1 + 0x284) = 1;

        }

        FUN_1400b87e0(lVar1);

      }

      if (*(char *)(param_1 + 0x259) == '\0') {

        *(undefined1 *)(param_1 + 0x259) = 1;

        local_28[0] = s_Betting_140303270[0];

        local_28[1] = s_Betting_140303270[1];

        local_28[2] = s_Betting_140303270[2];

        local_28[3] = s_Betting_140303270[3];

        local_24[0] = s_Betting_140303270[4];

        local_24[1] = s_Betting_140303270[5];

        local_22 = s_Betting_140303270[6];

        local_20 = 0;

        local_18 = 7;

        local_10 = 0xf;

        local_21 = 0;

        FUN_14003f340(local_28,1);

      }

      if (*(int *)(lVar1 + 0x1c) == 2) {

        iVar3 = FUN_1400c6580(3);

        if (iVar3 == 0) {

          FUN_1400b7fe0(lVar1,0);

        }

      }

      return 1;

    }

  }

  return 0;

}




