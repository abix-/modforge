// Address: 0x14014dc20
// Ghidra name: FUN_14014dc20
// ============ 0x14014dc20 FUN_14014dc20 (size=302) ============


void FUN_14014dc20(longlong param_1,char param_2)



{

  longlong lVar1;

  

  if (*(longlong *)(param_1 + 0xd8) != 0) {

    FUN_140155130(param_1,0);

  }

  FUN_1401747e0(*(undefined4 *)(param_1 + 0x134));

  lVar1 = *(longlong *)(param_1 + 0x10);

  if (param_2 == '\0') {

    if (param_1 == *(longlong *)(lVar1 + 0x1f0)) {

      FUN_140154ab0(lVar1,0);

    }

    else {

      FUN_140149dc0(param_1);

    }

  }

  FUN_1401aa9d0(param_1,3,0);

  if (*(longlong *)(param_1 + 0x148) != 0) {

    *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0x140) = *(undefined8 *)(param_1 + 0x140);

  }

  if (*(longlong *)(param_1 + 0x140) == 0) {

    *(undefined8 *)(lVar1 + 0x1e8) = *(undefined8 *)(param_1 + 0x148);

  }

  else {

    *(undefined8 *)(*(longlong *)(param_1 + 0x140) + 0x148) = *(undefined8 *)(param_1 + 0x148);

  }

  if (*(longlong *)(param_1 + 0xf8) != 0) {

    FUN_14014dc20(*(longlong *)(param_1 + 0xf8),param_2);

  }

  if (*(longlong *)(param_1 + 0x100) != 0) {

    FUN_140205da0();

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x108));

  (**(code **)(lVar1 + 0xd0))(lVar1,param_1);

  if (*(longlong *)(param_1 + 0xf0) != 0) {

    FUN_140146010();

    *(undefined8 *)(param_1 + 0xf0) = 0;

  }

  if (*(longlong *)(param_1 + 0x128) != 0) {

    FUN_140146010();

    *(undefined8 *)(param_1 + 0x128) = 0;

  }

  FUN_1401841e0(param_1);

  return;

}




