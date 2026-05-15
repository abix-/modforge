// Address: 0x1400296f0
// Ghidra name: FUN_1400296f0
// ============ 0x1400296f0 FUN_1400296f0 (size=183) ============


void FUN_1400296f0(longlong param_1,int param_2,longlong param_3,undefined8 *param_4,

                  undefined4 param_5)



{

  undefined *puVar1;

  longlong lVar2;

  

  if (*(char *)(param_1 + 0x68) == '\0') {

    if (0xf < param_2) {

      FID_conflict__assert

                (L"err > 0 && err < TIXML_ERROR_STRING_COUNT",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp"

                 ,0x324);

    }

    *(undefined1 *)(param_1 + 0x68) = 1;

    puVar1 = (&PTR_s_No_error_14039a3b0)[param_2];

    lVar2 = -1;

    *(int *)(param_1 + 0x6c) = param_2;

    do {

      lVar2 = lVar2 + 1;

    } while (puVar1[lVar2] != '\0');

    FUN_140027f50(param_1 + 0x70);

    *(undefined8 *)(param_1 + 0x94) = 0xffffffffffffffff;

    if ((param_3 != 0) && (param_4 != (undefined8 *)0x0)) {

      FUN_140028650(param_4,param_3,param_5);

      *(undefined8 *)(param_1 + 0x94) = *param_4;

    }

  }

  return;

}




