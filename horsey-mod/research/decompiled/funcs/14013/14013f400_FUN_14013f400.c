// Address: 0x14013f400
// Ghidra name: FUN_14013f400
// ============ 0x14013f400 FUN_14013f400 (size=119) ============


bool FUN_14013f400(void)



{

  bool bVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  bool bVar5;

  int local_res8 [2];

  

  local_res8[0] = 0;

  bVar5 = false;

  lVar3 = FUN_140158f60(local_res8);

  if (lVar3 == 0) {

    return false;

  }

  lVar4 = (longlong)(local_res8[0] + -1);

  bVar1 = false;

  if (-1 < local_res8[0] + -1) {

    do {

      bVar5 = true;

      if (bVar1) break;

      cVar2 = FUN_14013f5e0(*(undefined4 *)(lVar3 + lVar4 * 4));

      bVar5 = cVar2 != '\0';

      lVar4 = lVar4 + -1;

      bVar1 = bVar5;

    } while (-1 < lVar4);

  }

  FUN_1401841e0(lVar3);

  return bVar5;

}




