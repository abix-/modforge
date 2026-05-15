// Address: 0x140195800
// Ghidra name: FUN_140195800
// ============ 0x140195800 FUN_140195800 (size=355) ============


short * FUN_140195800(undefined8 param_1)



{

  short sVar1;

  int iVar2;

  longlong lVar3;

  short *psVar4;

  longlong lVar5;

  short *psVar6;

  short *psVar7;

  undefined4 local_res10 [2];

  

  psVar4 = (short *)0x0;

  psVar6 = (short *)0x0;

  lVar3 = FUN_1401960f0(param_1,&DAT_1403e3a78,0x12);

  psVar7 = psVar4;

  if ((((lVar3 != 0) && (iVar2 = (*DAT_1403fccb8)(local_res10,lVar3,0), psVar7 = psVar6, iVar2 == 0)

       ) && (iVar2 = (*DAT_1403fccc0)(local_res10,local_res10[0],0), iVar2 == 0)) &&

     (psVar4 = (short *)FUN_1401961b0(local_res10[0],&DAT_1403e3aa8,0x2012), psVar4 != (short *)0x0)

     ) {

    sVar1 = *psVar4;

    psVar6 = psVar4;

    while (psVar7 = (short *)0x0, sVar1 != 0) {

      FUN_140196470(psVar6);

      lVar5 = FUN_14012ffb0(psVar6,&DAT_14033a620);

      if (lVar5 != 0) {

        psVar7 = (short *)0x1;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"BTHENUM");

      if ((lVar5 != 0) || (lVar5 = FUN_14012ffb0(psVar6,L"BTHLEDEVICE"), lVar5 != 0)) {

        psVar7 = (short *)0x2;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"PNP0C50");

      if (lVar5 != 0) {

        psVar7 = (short *)0x3;

        break;

      }

      lVar5 = FUN_14012ffb0(psVar6,L"PNP0C51");

      if (lVar5 != 0) {

        psVar7 = (short *)0x4;

        break;

      }

      lVar5 = FUN_14012fd40(psVar6);

      psVar6 = psVar6 + lVar5 + 1;

      sVar1 = *psVar6;

    }

  }

  FUN_1401841e0(lVar3);

  FUN_1401841e0(psVar4);

  return psVar7;

}




