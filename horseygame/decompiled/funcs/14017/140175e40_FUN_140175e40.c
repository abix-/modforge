// Address: 0x140175e40
// Ghidra name: FUN_140175e40
// ============ 0x140175e40 FUN_140175e40 (size=168) ============


ulonglong FUN_140175e40(undefined2 param_1,undefined2 param_2)



{

  int iVar1;

  ulonglong uVar2;

  longlong lVar3;

  int local_res18 [2];

  longlong local_res20;

  

  local_res18[0] = 0;

  local_res20 = 0;

  uVar2 = 0xffffffff;

  FUN_140175ef0(&local_res20,local_res18);

  if ((local_res18[0] != 0) && (local_res20 != 0)) {

    lVar3 = local_res20;

    iVar1 = FUN_140176010(local_res20,local_res18[0],0xffff);

    if (-1 < iVar1) {

      uVar2 = (ulonglong)*(ushort *)(lVar3 + 4 + (longlong)iVar1 * 6);

    }

    iVar1 = FUN_140176010(lVar3,local_res18[0],param_1,param_2);

    if (-1 < iVar1) {

      uVar2 = (ulonglong)*(ushort *)(lVar3 + 4 + (longlong)iVar1 * 6);

    }

    FUN_1401841e0(lVar3);

  }

  return uVar2;

}




