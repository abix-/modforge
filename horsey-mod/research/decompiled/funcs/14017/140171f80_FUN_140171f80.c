// Address: 0x140171f80
// Ghidra name: FUN_140171f80
// ============ 0x140171f80 FUN_140171f80 (size=237) ============


undefined8 FUN_140171f80(longlong param_1,char param_2)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    lVar1 = DAT_1403fc410;

    uVar3 = *(ulonglong *)(param_1 + 0x48);

    if ((uVar3 & 0xc0000) == 0) {

      if (((param_2 != '\0') != (bool)((byte)(uVar3 >> 5) & 1)) &&

         (*(longlong *)(DAT_1403fc410 + 0xf0) != 0)) {

        if (param_2 == '\0') {

          uVar3 = uVar3 & 0xffffffffffffffdf;

          *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x7c);

          *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x80);

          *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x84);

          *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x88);

        }

        else {

          uVar3 = uVar3 | 0x20;

        }

        *(ulonglong *)(param_1 + 0x48) = uVar3;

        (**(code **)(lVar1 + 0xf0))(lVar1,param_1);

      }

      return 1;

    }

    FUN_14012e850("Operation invalid on popup windows");

    return 0;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




