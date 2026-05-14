// Address: 0x14022cf70
// Ghidra name: FUN_14022cf70
// ============ 0x14022cf70 FUN_14022cf70 (size=70) ============


void FUN_14022cf70(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if (lVar1 != 0) {

    if (*(HDC *)(lVar1 + 0x20) != (HDC)0x0) {

      DeleteDC(*(HDC *)(lVar1 + 0x20));

      *(undefined8 *)(lVar1 + 0x20) = 0;

    }

    if (*(HGDIOBJ *)(lVar1 + 0x30) != (HGDIOBJ)0x0) {

      DeleteObject(*(HGDIOBJ *)(lVar1 + 0x30));

      *(undefined8 *)(lVar1 + 0x30) = 0;

    }

  }

  return;

}




