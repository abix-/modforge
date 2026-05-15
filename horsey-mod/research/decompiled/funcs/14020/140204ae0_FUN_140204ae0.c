// Address: 0x140204ae0
// Ghidra name: FUN_140204ae0
// ============ 0x140204ae0 FUN_140204ae0 (size=159) ============


void FUN_140204ae0(undefined8 param_1,uint *param_2)



{

  longlong lVar1;

  uint uVar2;

  

  uVar2 = *param_2;

  lVar1 = *(longlong *)(param_2 + 0x4e);

  if ((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) {

    uVar2 = uVar2 & 0xff;

  }

  else if ((((uVar2 == 0x32595559) || (uVar2 == 0x59565955)) || (uVar2 == 0x55595659)) ||

          (uVar2 == 0x30313050)) {

    uVar2 = 2;

  }

  else {

    uVar2 = 1;

  }

  FUN_140204cb0(param_1,param_2,lVar1 + 0x24,

                (longlong)(*(int *)(lVar1 + 0x20) * *(int *)(lVar1 + 0x28)) +

                (longlong)(int)(uVar2 * *(int *)(lVar1 + 0x24)) + *(longlong *)(lVar1 + 0x18),

                *(int *)(lVar1 + 0x20));

  return;

}




