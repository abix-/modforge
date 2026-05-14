// Address: 0x140218bd0
// Ghidra name: FUN_140218bd0
// ============ 0x140218bd0 FUN_140218bd0 (size=91) ============


undefined8 FUN_140218bd0(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  

  local_28 = 0x3057;

  local_20 = 0x3056;

  local_18 = 0x3038;

  local_24 = param_2;

  local_1c = param_3;

  cVar2 = FUN_1402187e0();

  if (cVar2 == '\0') {

    return 0;

  }

  lVar1 = *(longlong *)(param_1 + 0x690);

  uVar3 = (**(code **)(lVar1 + 0x78))

                    (*(undefined8 *)(lVar1 + 0x10),*(undefined8 *)(lVar1 + 0x18),&local_28);

  return uVar3;

}




