// Address: 0x140164f60
// Ghidra name: FUN_140164f60
// ============ 0x140164f60 FUN_140164f60 (size=250) ============


char FUN_140164f60(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  int param_5,longlong param_6)



{

  char cVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  

  lVar4 = 0;

  iVar2 = 0;

  if ((param_6 != 0) && (lVar4 = FUN_140217c10(*(undefined8 *)(param_1 + 0x60)), lVar4 == 0)) {

    return '\0';

  }

  if (*(longlong *)(param_1 + 0x20) != 0) {

    iVar2 = FUN_1401677b0(param_1);

  }

  cVar1 = '\x01';

  if (lVar4 == 0) {

    cVar1 = FUN_140218250(*(undefined8 *)(param_1 + 0x60),param_2,param_3,param_4,(longlong)param_5)

    ;

    if (cVar1 == '\0') {

      return '\0';

    }

  }

  else {

    FUN_140217ac0(*(undefined8 *)(param_1 + 0x60),lVar4);

  }

  if (*(longlong *)(param_1 + 0x20) != 0) {

    iVar3 = FUN_1401677b0(param_1);

    (**(code **)(param_1 + 0x20))

              (*(undefined8 *)(param_1 + 0x28),param_1,iVar3 - iVar2,iVar3 - iVar2);

  }

  return cVar1;

}




