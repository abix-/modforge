// Address: 0x140075290
// Ghidra name: FUN_140075290
// ============ 0x140075290 FUN_140075290 (size=139) ============


ulonglong FUN_140075290(longlong *param_1,int param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined1 local_res10 [24];

  

  lVar1 = *param_1;

  uVar3 = param_1[1] - lVar1 >> 5;

  uVar2 = (ulonglong)(param_2 + (int)uVar3);

  if (uVar2 < uVar3) {

    param_1[1] = uVar2 * 0x20 + lVar1;

    return uVar3 & 0xffffffff;

  }

  if (uVar3 < uVar2) {

    if ((ulonglong)(param_1[2] - lVar1 >> 5) < uVar2) {

      FUN_140074c20(param_1,uVar2,local_res10);

      return uVar3 & 0xffffffff;

    }

    lVar1 = FUN_140074f30(param_1[1],uVar2 - uVar3,param_1);

    param_1[1] = lVar1;

  }

  return uVar3 & 0xffffffff;

}




