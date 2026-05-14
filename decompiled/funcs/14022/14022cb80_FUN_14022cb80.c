// Address: 0x14022cb80
// Ghidra name: FUN_14022cb80
// ============ 0x14022cb80 FUN_14022cb80 (size=77) ============


void FUN_14022cb80(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  longlong lVar1;

  int iVar2;

  undefined4 local_res18 [4];

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  if (*(longlong *)(lVar1 + 0x60) != 0) {

    local_res18[0] = param_3;

    iVar2 = FUN_1401a9900();

    if (iVar2 != 0) {

      (**(code **)(lVar1 + 0x60))(param_2,0x21,local_res18,4);

    }

  }

  return;

}




