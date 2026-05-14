// Address: 0x1401e7830
// Ghidra name: FUN_1401e7830
// ============ 0x1401e7830 FUN_1401e7830 (size=301) ============


int FUN_1401e7830(longlong param_1,longlong param_2,undefined8 param_3)



{

  longlong *plVar1;

  longlong lVar2;

  int iVar3;

  undefined8 uVar4;

  undefined4 local_58;

  undefined8 local_54;

  undefined4 local_4c;

  undefined4 local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined8 local_30;

  undefined4 local_28;

  undefined8 local_24;

  undefined8 local_1c;

  undefined4 local_14;

  undefined8 local_10;

  

  lVar2 = param_2 * 0x20 + param_1;

  plVar1 = (longlong *)(lVar2 + 0x110);

  if ((longlong *)*plVar1 != (longlong *)0x0) {

    (**(code **)(*(longlong *)*plVar1 + 0x10))();

    *plVar1 = 0;

  }

  local_54 = 0;

  local_4c = 1;

  local_48 = 1;

  local_40 = 1;

  local_28 = 1;

  local_1c = 1;

  local_14 = 1;

  local_58 = 2;

  local_10 = 0;

  local_38 = 0x10000;

  local_24 = 0x10001;

  local_30 = param_3;

  iVar3 = (**(code **)(**(longlong **)(param_1 + 0x30) + 0xd8))

                    (*(longlong **)(param_1 + 0x30),&local_58,0,&local_40,0xac3,0,&DAT_14034bc60,

                     plVar1);

  if (iVar3 < 0) {

    FUN_1401a9ef0("ID3D12Device::CreatePlacedResource [vertex buffer]",iVar3);

  }

  else {

    uVar4 = (**(code **)(*(longlong *)*plVar1 + 0x58))();

    *(undefined8 *)(lVar2 + 0x118) = uVar4;

    *(undefined4 *)(lVar2 + 0x124) = 0x20;

    *(undefined8 *)(lVar2 + 0x128) = param_3;

  }

  return iVar3;

}




