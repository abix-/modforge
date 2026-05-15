// Address: 0x140196270
// Ghidra name: FUN_140196270
// ============ 0x140196270 FUN_140196270 (size=512) ============


void FUN_140196270(longlong param_1,undefined4 param_2)



{

  short sVar1;

  int iVar2;

  short *psVar3;

  short *psVar4;

  longlong lVar5;

  undefined8 uVar6;

  short *psVar7;

  undefined4 local_res10 [2];

  undefined4 local_res18 [2];

  

  psVar4 = (short *)0x0;

  local_res10[0] = param_2;

  psVar3 = (short *)FUN_1401961b0(param_2,&DAT_1403e3a78,0x12);

  if (psVar3 != (short *)0x0) {

    FUN_140196470(psVar3);

    iVar2 = FUN_140195da0(psVar3,&DAT_14033a600);

    if (((iVar2 == -1) || (iVar2 = (*DAT_1403fccc0)(local_res10,local_res10[0],0), iVar2 == 0)) &&

       (psVar4 = (short *)FUN_1401961b0(local_res10[0],&DAT_1403e3a90,0x2012),

       psVar4 != (short *)0x0)) {

      sVar1 = *psVar4;

      psVar7 = psVar4;

      while (sVar1 != 0) {

        FUN_140196470(psVar7);

        if ((*(short *)(param_1 + 0x18) == 0) &&

           (iVar2 = FUN_140195da0(psVar7,L"REV_"), iVar2 != -1)) {

          *(short *)(param_1 + 0x18) = (short)iVar2;

        }

        if ((*(int *)(param_1 + 0x34) == -1) &&

           (iVar2 = FUN_140195da0(psVar7,&DAT_14033a618), iVar2 != -1)) {

          *(int *)(param_1 + 0x34) = iVar2;

        }

        lVar5 = FUN_14012fd40(psVar7);

        psVar7 = psVar7 + lVar5 + 1;

        sVar1 = *psVar7;

      }

      lVar5 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x20));

      if ((lVar5 == 0) && (lVar5 = FUN_1401961b0(local_res10[0],&DAT_1403e3a60,0x12), lVar5 != 0)) {

        FUN_1401841e0(*(undefined8 *)(param_1 + 0x20));

        *(longlong *)(param_1 + 0x20) = lVar5;

      }

      lVar5 = FUN_14012fd40(*(undefined8 *)(param_1 + 0x10));

      if (lVar5 == 0) {

        local_res18[0] = local_res10[0];

        if ((*(int *)(param_1 + 0x34) != -1) &&

           (iVar2 = (*DAT_1403fccc0)(local_res18,local_res10[0],0), iVar2 != 0)) goto LAB_140196458;

        FUN_1401841e0(psVar3);

        psVar3 = (short *)FUN_1401961b0(local_res18[0],&DAT_1403e3a78,0x12);

        if (psVar3 == (short *)0x0) goto LAB_140196458;

        lVar5 = FUN_14012fd40(psVar3);

        psVar7 = psVar3 + lVar5;

        while( true ) {

          if ((psVar7 <= psVar3) || (*psVar7 == 0x26)) goto LAB_140196441;

          if (*psVar7 == 0x5c) break;

          psVar7 = psVar7 + -1;

        }

        FUN_1401841e0(*(undefined8 *)(param_1 + 0x10));

        uVar6 = FUN_14012fc00(psVar7 + 1);

        *(undefined8 *)(param_1 + 0x10) = uVar6;

      }

LAB_140196441:

      if (*(int *)(param_1 + 0x34) == -1) {

        *(undefined4 *)(param_1 + 0x34) = 0;

      }

    }

  }

LAB_140196458:

  FUN_1401841e0(psVar3);

  FUN_1401841e0(psVar4);

  return;

}




