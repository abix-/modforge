// Address: 0x1401cba40
// Ghidra name: FUN_1401cba40
// ============ 0x1401cba40 FUN_1401cba40 (size=117) ============


undefined8 FUN_1401cba40(longlong param_1,longlong *param_2)



{

  int iVar1;

  code *pcVar2;

  

  if (param_2 == (longlong *)0x0) {

    pcVar2 = (code *)FUN_140188550(*(undefined8 *)(param_1 + 0x68),"D3D12GetDebugInterface");

    if (pcVar2 == (code *)0x0) {

      return 0;

    }

    iVar1 = (*pcVar2)(&DAT_140349378,param_1 + 0x58);

  }

  else {

    iVar1 = (**(code **)(*param_2 + 0x38))(param_2,&DAT_1403493b8,&DAT_140349378,param_1 + 0x58);

  }

  if (iVar1 < 0) {

    return 0;

  }

  (**(code **)(**(longlong **)(param_1 + 0x58) + 0x18))();

  return 1;

}




