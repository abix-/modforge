// Address: 0x1401693d0
// Ghidra name: FUN_1401693d0
// ============ 0x1401693d0 FUN_1401693d0 (size=158) ============


longlong FUN_1401693d0(longlong param_1,undefined8 param_2,longlong *param_3)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = 0;

  if (*(longlong *)(param_1 + 0x360) != 0) {

    cVar1 = FUN_140169620();

    if (cVar1 == '\0') {

      lVar3 = 0;

    }

    else {

      lVar2 = (**(code **)(param_1 + 0x360))(*(undefined8 *)(param_1 + 0x370),param_2,param_3);

      if (lVar2 != 0) {

        lVar3 = FUN_1401841f0(*param_3 + 4);

        if (lVar3 == 0) {

          *param_3 = 0;

        }

        else {

          FUN_1402f8e20(lVar3,lVar2,*param_3);

          *(undefined4 *)(lVar3 + *param_3) = 0;

        }

      }

    }

  }

  return lVar3;

}




