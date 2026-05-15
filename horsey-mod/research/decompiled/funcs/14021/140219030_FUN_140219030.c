// Address: 0x140219030
// Ghidra name: FUN_140219030
// ============ 0x140219030 FUN_140219030 (size=174) ============


longlong FUN_140219030(longlong param_1,undefined8 param_2)



{

  code *pcVar1;

  longlong lVar2;

  uint uVar3;

  

  lVar2 = *(longlong *)(param_1 + 0x690);

  if (lVar2 == 0) {

    return 0;

  }

  uVar3 = *(int *)(lVar2 + 0x28) << 0x10 | *(uint *)(lVar2 + 0x2c);

  if (((0x10004 < uVar3) && (*(code **)(lVar2 + 0x58) != (code *)0x0)) &&

     (lVar2 = (**(code **)(lVar2 + 0x58))(param_2), lVar2 != 0)) {

    return lVar2;

  }

  lVar2 = FUN_140188550(**(undefined8 **)(param_1 + 0x690),param_2);

  if ((lVar2 == 0) && (uVar3 < 0x10005)) {

    pcVar1 = *(code **)(*(longlong *)(param_1 + 0x690) + 0x58);

    if (pcVar1 == (code *)0x0) {

      return 0;

    }

    lVar2 = (*pcVar1)(param_2);

  }

  return lVar2;

}




