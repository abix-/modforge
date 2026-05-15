// Address: 0x1401b1590
// Ghidra name: FUN_1401b1590
// ============ 0x1401b1590 FUN_1401b1590 (size=195) ============


void FUN_1401b1590(longlong param_1,longlong *param_2,int param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  lVar2 = *param_2;

  FUN_1401b3e30(lVar1,param_1);

  if (*(char *)(lVar1 + 0x593) == '\0') {

    uVar3 = 0;

    if (param_4 != 0) {

      do {

        (**(code **)(lVar1 + 0xaa0))

                  (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(lVar2 + 0x10),

                   param_3 + uVar3 * 0x14,1,0x14);

        uVar3 = uVar3 + 1;

      } while (uVar3 < param_4);

    }

  }

  else {

    (**(code **)(lVar1 + 0xaa0))

              (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(lVar2 + 0x10),param_3,param_4,0x14);

  }

  FUN_1401bd730(param_1,lVar2);

  return;

}




