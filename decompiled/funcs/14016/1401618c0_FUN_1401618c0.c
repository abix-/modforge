// Address: 0x1401618c0
// Ghidra name: FUN_1401618c0
// ============ 0x1401618c0 FUN_1401618c0 (size=213) ============


void FUN_1401618c0(longlong param_1,undefined4 param_2,undefined4 param_3,char param_4)



{

  longlong lVar1;

  

  lVar1 = FUN_1401611a0();

  if (((param_1 != 0) || (param_1 = *(longlong *)(lVar1 + 0x88), param_1 != 0)) &&

     ((*(byte *)(param_1 + 0x48) & 0x40) == 0)) {

    *(undefined4 *)(lVar1 + 0xa0) = param_2;

    *(undefined4 *)(lVar1 + 0xa4) = param_3;

    *(undefined1 *)(lVar1 + 0xc0) = 0;

    if (((*(char *)(lVar1 + 0xc1) == '\0') || (param_4 != '\0')) ||

       (*(char *)(lVar1 + 0xc2) != '\0')) {

      if ((*(code **)(lVar1 + 0x30) == (code *)0x0) || (*(char *)(lVar1 + 0xc1) != '\0')) {

        FUN_140161f10(0,param_1,0,0,param_2,param_3);

      }

      else {

        (**(code **)(lVar1 + 0x30))(param_1,param_2,param_3);

      }

    }

    else {

      *(undefined4 *)(lVar1 + 0x90) = param_2;

      *(undefined4 *)(lVar1 + 0x94) = param_3;

      *(undefined1 *)(lVar1 + 0xc0) = 1;

    }

  }

  return;

}




