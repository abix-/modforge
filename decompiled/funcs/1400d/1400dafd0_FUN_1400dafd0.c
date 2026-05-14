// Address: 0x1400dafd0
// Ghidra name: FUN_1400dafd0
// ============ 0x1400dafd0 FUN_1400dafd0 (size=663) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400dafd0(undefined8 param_1)



{

  int iVar1;

  longlong lVar2;

  undefined2 local_res10 [4];

  int local_res18 [4];

  

  lVar2 = FUN_1402ce0f8(param_1,&DAT_14030a390);

  if (lVar2 == 0) {

    return 0;

  }

  FUN_1402d185c(&DAT_14030ebc4,4,1,lVar2);

  local_res18[0] = 0;

  FUN_1402d185c(local_res18,1,4,lVar2);

  FUN_1402d185c(&DAT_14030ebcc,4,1,lVar2);

  FUN_1402d185c(&DAT_14030ebd4,4,1,lVar2);

  local_res18[0] = 0x10;

  FUN_1402d185c(local_res18,1,4,lVar2);

  local_res10[0] = 1;

  FUN_1402d185c(local_res10,1,2,lVar2);

  local_res10[0] = 1;

  FUN_1402d185c(local_res10,1,2,lVar2);

  local_res18[0] = DAT_1403da914;

  FUN_1402d185c(local_res18,1,4,lVar2);

  local_res18[0] =

       (int)(DAT_1403da910 * DAT_1403da914 + (DAT_1403da910 * DAT_1403da914 >> 0x1f & 7U)) >> 3;

  FUN_1402d185c(local_res18,1,4,lVar2);

  local_res10[0] = (undefined2)((int)(DAT_1403da910 + (DAT_1403da910 >> 0x1f & 7U)) >> 3);

  FUN_1402d185c(local_res10,1,2,lVar2);

  local_res10[0] = (undefined2)DAT_1403da910;

  FUN_1402d185c(local_res10,1,2,lVar2);

  FUN_1402d185c(&DAT_14030ebdc,4,1,lVar2);

  local_res18[0] = 0;

  iVar1 = FUN_1402cf00c(lVar2);

  FUN_1402d185c(local_res18,1,4,lVar2);

  DAT_1403f4ba0 = 0;

  _DAT_1403f4ba4 = 0;

  DAT_1403f4ba8 = 0;

  FUN_1400d98f0(0);

  DAT_1403f3a59 = '\x01';

  do {

    FUN_1400da2f0(0x100,0,lVar2);

  } while (DAT_1403f3a59 != '\0');

  FUN_1402cea4c(lVar2,4,0);

  local_res18[0] =

       ((int)((DAT_1403f4ba0 * DAT_1403da910 >> 0x1f & 7U) + DAT_1403f4ba0 * DAT_1403da910) >> 3) +

       -4 + iVar1;

  FUN_1402d185c(local_res18,1,4,lVar2);

  FUN_1402cea4c(lVar2,iVar1,0);

  local_res18[0] =

       (int)(DAT_1403f4ba0 * DAT_1403da910 + (DAT_1403f4ba0 * DAT_1403da910 >> 0x1f & 7U)) >> 3;

  FUN_1402d185c(local_res18,1,4,lVar2);

  FUN_1402ce288(lVar2);

  return 1;

}




