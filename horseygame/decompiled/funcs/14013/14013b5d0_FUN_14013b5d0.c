// Address: 0x14013b5d0
// Ghidra name: FUN_14013b5d0
// ============ 0x14013b5d0 FUN_14013b5d0 (size=357) ============


void FUN_14013b5d0(uint param_1,char param_2)



{

  bool bVar1;

  longlong lVar2;

  uint uVar3;

  

  uVar3 = param_1 & 0xff;

  lVar2 = (&DAT_1403fb6a0)[param_1 >> 8 & 0xff];

  if ((lVar2 == 0) ||

     (bVar1 = false, (*(uint *)(lVar2 + (ulonglong)(uVar3 >> 5) * 4) >> (param_1 & 0x1f) & 1) == 0))

  {

    bVar1 = true;

  }

  if ((param_2 != '\0') == bVar1) {

    return;

  }

  if (param_2 == '\0') {

    if (lVar2 == 0) {

      lVar2 = FUN_1401841a0(1,0x20);

      (&DAT_1403fb6a0)[param_1 >> 8 & 0xff] = lVar2;

      if (lVar2 == 0) goto switchD_14013b673_caseD_655;

    }

    *(uint *)(lVar2 + (ulonglong)(uVar3 >> 5) * 4) =

         *(uint *)(lVar2 + (ulonglong)(uVar3 >> 5) * 4) | 1 << (param_1 & 0x1f);

    FUN_140139550(param_1);

    goto switchD_14013b673_caseD_655;

  }

  *(uint *)(lVar2 + (ulonglong)(uVar3 >> 5) * 4) =

       *(uint *)(lVar2 + (ulonglong)(uVar3 >> 5) * 4) & ~(1 << (param_1 & 0x1f));

  switch(param_1) {

  case 0x650:

  case 0x651:

  case 0x652:

    FUN_14013b5d0(0x600,1);

    FUN_14013b5d0(0x602,1);

    FUN_14013b5d0(0x603,1);

    FUN_14013b5d0(0x604,1);

  default:

switchD_14013b673_caseD_655:

    if (param_1 - 0x1000 < 2) {

      FUN_140173020();

    }

    break;

  case 0x653:

    FUN_14013b5d0(0x605,1);

    break;

  case 0x654:

    FUN_14013b5d0(0x606,1);

    break;

  case 0x65a:

    FUN_14013b5d0(0x608,1);

  }

  return;

}




