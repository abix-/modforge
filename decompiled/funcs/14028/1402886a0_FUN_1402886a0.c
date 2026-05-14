// Address: 0x1402886a0
// Ghidra name: FUN_1402886a0
// ============ 0x1402886a0 FUN_1402886a0 (size=134) ============


bool FUN_1402886a0(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  int iVar2;

  undefined4 local_8a8;

  undefined1 local_8a4 [1100];

  undefined4 local_458;

  undefined1 local_454 [1100];

  

  local_458 = 0x44c;

  local_8a8 = 0x44c;

  iVar2 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x78))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),&local_458);

  if (-1 < iVar2) {

    plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x148) + 0x10);

    iVar2 = (**(code **)(*plVar1 + 0x78))(plVar1,&local_8a8);

    if (-1 < iVar2) {

      iVar2 = FUN_1401a98e0(local_454,local_8a4);

      return iVar2 == 1;

    }

  }

  return false;

}




