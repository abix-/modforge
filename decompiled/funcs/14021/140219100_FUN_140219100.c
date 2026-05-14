// Address: 0x140219100
// Ghidra name: FUN_140219100
// ============ 0x140219100 FUN_140219100 (size=166) ============


void FUN_140219100(longlong param_1)



{

  code *pcVar1;

  int iVar2;

  longlong lVar3;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x690) + 0xa8);

  if ((pcVar1 != (code *)0x0) &&

     (lVar3 = (*pcVar1)(*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),0x3054), lVar3 != 0))

  {

    local_res8[0] = 0;

    local_res10[0] = 0;

    iVar2 = FUN_14012ef30(lVar3,"%d.%d",local_res8,local_res10);

    if (iVar2 == 2) {

      *(undefined4 *)(*(longlong *)(param_1 + 0x690) + 0x28) = local_res8[0];

      *(undefined4 *)(*(longlong *)(param_1 + 0x690) + 0x2c) = local_res10[0];

      return;

    }

    FUN_14012e2e0(5,"Could not parse EGL version string: %s",lVar3);

  }

  return;

}




