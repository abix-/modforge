// Address: 0x14020d770
// Ghidra name: FUN_14020d770
// ============ 0x14020d770 FUN_14020d770 (size=278) ============


undefined8 FUN_14020d770(undefined8 param_1,undefined8 param_2,undefined8 *param_3)



{

  undefined4 uVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  longlong *plVar5;

  longlong lVar6;

  int iVar7;

  longlong *local_res20;

  

  iVar7 = 0;

  local_res20 = (longlong *)0x0;

  FUN_140159d30();

  cVar3 = FUN_140159a50();

  if ((cVar3 != '\0') &&

     (iVar4 = (**(code **)*param_3)(param_3,&DAT_1403505f8,&local_res20), lVar2 = DAT_1403fd2f8,

     -1 < iVar4)) {

    if (0 < DAT_1403fd2f0) {

      plVar5 = (longlong *)(DAT_1403fd2f8 + 8);

      do {

        if ((longlong *)*plVar5 == local_res20) {

          lVar6 = (longlong)iVar7;

          uVar1 = *(undefined4 *)(DAT_1403fd2f8 + lVar6 * 0x30);

          (**(code **)(**(longlong **)(DAT_1403fd2f8 + 8 + lVar6 * 0x30) + 0x10))();

          FUN_1401841e0(*(undefined8 *)(lVar2 + 0x10 + lVar6 * 0x30));

          DAT_1403fd2f0 = DAT_1403fd2f0 + -1;

          if (iVar7 < DAT_1403fd2f0) {

            FUN_1402f8e20(DAT_1403fd2f8 + lVar6 * 0x30,(longlong)(iVar7 + 1) * 0x30 + DAT_1403fd2f8,

                          (longlong)(DAT_1403fd2f0 - iVar7) * 0x30);

          }

          FUN_14015a550(uVar1);

          break;

        }

        iVar7 = iVar7 + 1;

        plVar5 = plVar5 + 6;

      } while (iVar7 < DAT_1403fd2f0);

    }

    (**(code **)(*local_res20 + 0x10))();

  }

  FUN_14015bb10();

  return 0;

}




