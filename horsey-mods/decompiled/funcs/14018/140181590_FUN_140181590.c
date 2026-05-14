// Address: 0x140181590
// Ghidra name: FUN_140181590
// ============ 0x140181590 FUN_140181590 (size=75) ============


bool FUN_140181590(longlong param_1)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  undefined8 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  if ((*(longlong *)(lVar1 + 200) != 0) && (*(code **)(lVar1 + 0xa0) != (code *)0x0)) {

    pcVar2 = *(code **)(lVar1 + 200);

    uVar4 = (**(code **)(lVar1 + 0xa0))();

    iVar3 = (*pcVar2)(0xfffffffffffffffc,uVar4);

    return iVar3 != 0;

  }

  return false;

}




