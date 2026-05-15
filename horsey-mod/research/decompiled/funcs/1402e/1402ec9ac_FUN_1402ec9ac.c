// Address: 0x1402ec9ac
// Ghidra name: FUN_1402ec9ac
// ============ 0x1402ec9ac FUN_1402ec9ac (size=101) ============


int FUN_1402ec9ac(void)



{

  char cVar1;

  int iVar2;

  int local_res8 [8];

  

  if (DAT_1403ff630 != 0) {

    return DAT_1403ff630;

  }

  iVar2 = 2;

  local_res8[0] = 2;

  cVar1 = FUN_1402f0e08();

  if (cVar1 == '\0') {

    FUN_1402ec2f0(local_res8);

  }

  if (local_res8[0] != 0) {

    if (local_res8[0] == 1) goto LAB_1402eca01;

    if (local_res8[0] == 2) {

      iVar2 = 1;

      goto LAB_1402eca01;

    }

    if (local_res8[0] == 3) {

      iVar2 = 3;

      goto LAB_1402eca01;

    }

  }

  iVar2 = 4;

LAB_1402eca01:

  LOCK();

  UNLOCK();

  DAT_1403ff630 = iVar2;

  return iVar2;

}




