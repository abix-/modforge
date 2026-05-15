// Address: 0x1401644e0
// Ghidra name: FUN_1401644e0
// ============ 0x1401644e0 FUN_1401644e0 (size=150) ============


longlong FUN_1401644e0(longlong param_1,undefined8 *param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong local_res8;

  undefined8 local_res10;

  

  local_res8 = FUN_140217b30(*(undefined8 *)(param_1 + 0x60));

  local_res10 = *(undefined8 *)(param_1 + 0xa0);

  lVar2 = 0;

  do {

    if (local_res8 == 0) goto LAB_140164559;

    lVar1 = FUN_140164d70(param_1,&local_res8,&local_res10,0,0,0);

    lVar2 = lVar2 + lVar1;

  } while (lVar2 < 0x7fffffff);

  lVar2 = 0x7fffffff;

LAB_140164559:

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = local_res10;

  }

  return lVar2;

}




