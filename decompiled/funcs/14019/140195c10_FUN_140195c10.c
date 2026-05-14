// Address: 0x140195c10
// Ghidra name: FUN_140195c10
// ============ 0x140195c10 FUN_140195c10 (size=400) ============


undefined8 * FUN_140195c10(undefined8 *param_1,undefined8 param_2)



{

  short sVar1;

  int iVar2;

  longlong lVar3;

  short *psVar4;

  longlong lVar5;

  short *psVar6;

  undefined4 local_res8 [2];

  

  psVar4 = (short *)0x0;

  *param_1 = 0;

  *(undefined4 *)(param_1 + 1) = 0;

  lVar3 = FUN_1401960f0(param_2,&DAT_1403e3a78,0x12);

  if ((((lVar3 != 0) && (iVar2 = (*DAT_1403fccb8)(local_res8,lVar3,0), iVar2 == 0)) &&

      (iVar2 = (*DAT_1403fccc0)(local_res8,local_res8[0],0), iVar2 == 0)) &&

     (psVar4 = (short *)FUN_1401961b0(local_res8[0],&DAT_1403e3aa8,0x2012), psVar4 != (short *)0x0))

  {

    sVar1 = *psVar4;

    psVar6 = psVar4;

    while (sVar1 != 0) {

      FUN_140196470(psVar6);

      lVar5 = FUN_14012ffb0(psVar6,&DAT_14033a620);

      if (lVar5 != 0) {

        *(undefined4 *)((longlong)param_1 + 4) = 1;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"BTHENUM");

      if (lVar5 != 0) {

        *(undefined4 *)((longlong)param_1 + 4) = 2;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"BTHLEDEVICE");

      if (lVar5 != 0) {

        *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) | 1;

        *(undefined4 *)((longlong)param_1 + 4) = 2;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"PNP0C50");

      if (lVar5 != 0) {

        *(undefined4 *)((longlong)param_1 + 4) = 3;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"PNP0C51");

      if (lVar5 != 0) {

        *(undefined4 *)((longlong)param_1 + 4) = 4;

        break;

      }

      lVar5 = FUN_14012fd40(psVar6);

      psVar6 = psVar6 + lVar5 + 1;

      sVar1 = *psVar6;

    }

    *(undefined4 *)param_1 = local_res8[0];

  }

  FUN_1401841e0(lVar3);

  FUN_1401841e0(psVar4);

  return param_1;

}




