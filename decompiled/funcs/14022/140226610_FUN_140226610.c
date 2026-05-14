// Address: 0x140226610
// Ghidra name: FUN_140226610
// ============ 0x140226610 FUN_140226610 (size=583) ============


char * FUN_140226610(longlong param_1,undefined8 param_2)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  longlong lVar4;

  char *pcVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  char *pcVar9;

  uint local_res8 [2];

  uint local_res18 [4];

  undefined4 local_248;

  undefined4 local_244;

  undefined8 local_240;

  undefined4 local_238;

  undefined8 local_234;

  undefined8 uStack_22c;

  undefined8 local_224;

  undefined8 uStack_21c;

  undefined8 local_214;

  undefined8 uStack_20c;

  undefined8 local_204;

  undefined8 uStack_1fc;

  undefined4 local_1e8;

  undefined4 local_1e4;

  undefined8 local_1e0;

  undefined4 local_1d8;

  undefined1 local_1d4 [16];

  undefined1 local_1c4 [396];

  

  pcVar7 = (char *)0x0;

  pcVar9 = (char *)0x0;

  local_res8[0] = 0;

  local_res18[0] = 0;

  if (((*(longlong *)(param_1 + 0x18) == 0) || (*(longlong *)(param_1 + 0x20) == 0)) ||

     (pcVar3 = pcVar7, pcVar2 = pcVar7, *(longlong *)(param_1 + 0x28) == 0)) {

LAB_140226843:

    pcVar5 = (char *)0x0;

  }

  else {

    do {

      iVar1 = (**(code **)(param_1 + 0x18))(2,local_res8,local_res18);

      if (iVar1 != 0) {

LAB_14022682c:

        FUN_1401841e0(0);

        FUN_1401841e0(pcVar2);

        FUN_1401841e0(pcVar3);

        goto LAB_140226843;

      }

      FUN_1401841e0(pcVar2);

      FUN_1401841e0(pcVar3);

      pcVar2 = (char *)FUN_1401841f0((ulonglong)local_res8[0] * 0x48);

      pcVar3 = (char *)FUN_1401841f0((ulonglong)local_res18[0] << 6);

      if ((pcVar2 == (char *)0x0) || (pcVar3 == (char *)0x0)) goto LAB_14022682c;

      iVar1 = (**(code **)(param_1 + 0x20))(2,local_res8,pcVar2,local_res18,pcVar3,0);

    } while (iVar1 == 0x7a);

    pcVar5 = pcVar7;

    if ((iVar1 == 0) && (pcVar8 = pcVar7, pcVar5 = pcVar9, local_res8[0] != 0)) {

      while( true ) {

        local_234 = 0;

        uStack_22c = 0;

        local_248 = 1;

        local_224 = 0;

        uStack_21c = 0;

        local_244 = 0x54;

        local_240 = *(undefined8 *)(pcVar2 + (longlong)pcVar8 * 0x48 + 0x14);

        local_238 = *(undefined4 *)(pcVar2 + (longlong)pcVar8 * 0x48 + 8);

        local_214 = 0;

        uStack_20c = 0;

        local_204 = 0;

        uStack_1fc = 0;

        iVar1 = (**(code **)(param_1 + 0x28))(&local_248);

        pcVar5 = pcVar7;

        if (iVar1 != 0) break;

        iVar1 = FUN_14012fbc0(param_2,&local_234);

        if (iVar1 == 0) {

          FUN_1402f94c0(local_1d4,0,400);

          local_1e0 = *(undefined8 *)(pcVar2 + (longlong)pcVar8 * 0x48 + 0x14);

          local_1d8 = *(undefined4 *)(pcVar2 + (longlong)pcVar8 * 0x48 + 0x1c);

          local_1e8 = 2;

          local_1e4 = 0x1a4;

          iVar1 = (**(code **)(param_1 + 0x28))(&local_1e8);

          pcVar5 = pcVar9;

          if (iVar1 == 0) {

            lVar4 = FUN_14012fd40(local_1c4);

            pcVar5 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_1c4,lVar4 * 2 + 2);

            if ((pcVar5 != (char *)0x0) && (*pcVar5 == '\0')) {

              FUN_1401841e0(pcVar5);

              pcVar5 = (char *)0x0;

            }

          }

          break;

        }

        uVar6 = (int)pcVar8 + 1;

        pcVar8 = (char *)(ulonglong)uVar6;

        pcVar5 = pcVar9;

        if (local_res8[0] <= uVar6) break;

      }

    }

    FUN_1401841e0(pcVar2);

    FUN_1401841e0(pcVar3);

  }

  return pcVar5;

}




