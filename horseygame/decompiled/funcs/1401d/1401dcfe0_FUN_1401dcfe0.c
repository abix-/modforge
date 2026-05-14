// Address: 0x1401dcfe0
// Ghidra name: FUN_1401dcfe0
// ============ 0x1401dcfe0 FUN_1401dcfe0 (size=103) ============


undefined8 FUN_1401dcfe0(longlong *param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  

  if (*(longlong *)(param_2 + 0x20) == 0) {

    iVar1 = (**(code **)(*param_1 + 0xb8))

                      (param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),1,0,

                       *(undefined4 *)(param_2 + 0x14),2,param_2 + 0x20,0);

    if (iVar1 < 0) {

      uVar2 = FUN_1401df290("CreateTexture(D3DPOOL_SYSTEMMEM)",iVar1);

      return uVar2;

    }

  }

  return 1;

}




