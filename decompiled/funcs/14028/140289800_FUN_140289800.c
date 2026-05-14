// Address: 0x140289800
// Ghidra name: FUN_140289800
// ============ 0x140289800 FUN_140289800 (size=337) ============


void FUN_140289800(longlong *param_1,undefined8 *param_2,undefined8 *param_3,LPCLSID param_4)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  longlong *local_res8;

  undefined8 local_28;

  LPCOLESTR pOStack_20;

  undefined8 local_18;

  

  *param_2 = 0;

  *param_3 = 0;

  param_3[1] = 0;

  local_res8 = (longlong *)0x0;

  param_3[2] = 0;

  param_3[3] = 0;

  param_3[4] = 0;

  iVar1 = (**(code **)(*param_1 + 0x20))(0,0,&local_res8);

  if (-1 < iVar1) {

    local_18 = 0;

    local_28 = 0;

    pOStack_20 = (LPCOLESTR)0x0;

    iVar1 = (**(code **)(*local_res8 + 0x28))(local_res8,&DAT_140380c98,&local_28);

    if (-1 < iVar1) {

      lVar2 = FUN_14012fd40(pOStack_20);

      uVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",pOStack_20,lVar2 * 2 + 2);

      *param_2 = uVar3;

    }

    PropVariantClear((PROPVARIANT *)&local_28);

    iVar1 = (**(code **)(*local_res8 + 0x28))(local_res8,&DAT_140380cb0,&local_28);

    if (-1 < iVar1) {

      uVar4 = (ulonglong)pOStack_20 & 0xffffffff;

      if (0x27 < (uint)pOStack_20) {

        uVar4 = 0x28;

      }

      FUN_1402f8e20(param_3,local_18,uVar4);

    }

    PropVariantClear((PROPVARIANT *)&local_28);

    iVar1 = (**(code **)(*local_res8 + 0x28))(local_res8,&DAT_140380cc8,&local_28);

    if (-1 < iVar1) {

      CLSIDFromString(pOStack_20,param_4);

    }

    PropVariantClear((PROPVARIANT *)&local_28);

    (**(code **)(*local_res8 + 0x10))();

  }

  return;

}




