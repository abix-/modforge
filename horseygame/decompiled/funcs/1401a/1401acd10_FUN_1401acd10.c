// Address: 0x1401acd10
// Ghidra name: FUN_1401acd10
// ============ 0x1401acd10 FUN_1401acd10 (size=120) ============


undefined8 FUN_1401acd10(longlong *param_1,undefined8 param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined4 local_res8 [4];

  LPVOID local_res18 [2];

  

  local_res18[0] = (LPVOID)0x0;

  local_res8[0] = 0;

  iVar1 = (**(code **)(*param_1 + 0x68))(param_1,param_2,local_res18,local_res8);

  if (iVar1 < 0) {

    return 0;

  }

  lVar2 = FUN_14012fd40(local_res18[0]);

  uVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_res18[0],lVar2 * 2 + 2);

  CoTaskMemFree(local_res18[0]);

  return uVar3;

}




