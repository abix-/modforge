// Address: 0x14026cae0
// Ghidra name: FUN_14026cae0
// ============ 0x14026cae0 FUN_14026cae0 (size=129) ============


void FUN_14026cae0(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  double dVar4;

  

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    lVar1 = thunk_FUN_1402c9190(param_4,0x2e);

    if (lVar1 == 0) {

      cVar2 = FUN_1401429e0(param_4,1);

      uVar3 = -(uint)(cVar2 != '\0') & 100;

    }

    else {

      dVar4 = (double)thunk_FUN_1402de5ec();

      uVar3 = (uint)(dVar4 * DAT_14030ec28);

      if (0xff < (int)uVar3) {

        FUN_14026ce50(param_1,0xff);

        return;

      }

    }

    FUN_14026ce50(param_1,uVar3);

  }

  return;

}




