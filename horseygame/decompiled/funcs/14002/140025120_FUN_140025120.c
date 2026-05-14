// Address: 0x140025120
// Ghidra name: FUN_140025120
// ============ 0x140025120 FUN_140025120 (size=497) ============


longlong * FUN_140025120(longlong *param_1,longlong *param_2)



{

  longlong *plVar1;

  longlong *plVar2;

  undefined *puVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong *plVar7;

  

  plVar7 = param_2;

  if (((longlong *)param_2[3] != (longlong *)0x0) && ((longlong *)param_2[3] != param_1)) {

    FID_conflict__assert

              (L"node->parent == 0 || node->parent == this",L"C:\\dev\\tinyxml\\tinyxml.cpp",0xbc);

  }

  do {

    lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

    lVar6 = 0;

    if (lVar4 != 0) {

      lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

      plVar7 = param_2;

      if (lVar4 != 0) goto LAB_1400251a0;

      break;

    }

    plVar2 = plVar7 + 3;

    plVar7 = (longlong *)*plVar2;

  } while ((longlong *)*plVar2 != (longlong *)0x0);

LAB_140025210:

  if ((int)param_2[4] == 0) {

    (**(code **)*param_2)(param_2,1);

    plVar7 = param_1;

    if (param_1 == (longlong *)0x0) {

LAB_1400252ce:

      param_2 = (longlong *)0x0;

    }

    else {

      do {

        lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

        if (lVar4 != 0) {

          lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

          if (lVar4 != 0) goto LAB_140025267;

          goto LAB_1400252ce;

        }

        plVar7 = (longlong *)plVar7[3];

      } while (plVar7 != (longlong *)0x0);

      param_2 = (longlong *)0x0;

    }

  }

  else {

    param_2[3] = (longlong)param_1;

    param_2[0xb] = param_1[6];

    param_2[0xc] = 0;

    if (param_1[6] == 0) {

      param_1[5] = (longlong)param_2;

    }

    else {

      *(longlong **)(param_1[6] + 0x60) = param_2;

    }

    param_1[6] = (longlong)param_2;

  }

  return param_2;

  while (plVar1 = plVar7 + 3, plVar7 = (longlong *)*plVar1, lVar4 = lVar6,

        (longlong *)*plVar1 != (longlong *)0x0) {

LAB_1400251a0:

    lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

    plVar2 = param_1;

    if (lVar4 != 0) {

      lVar4 = (**(code **)(*plVar7 + 0x20))(plVar7);

      break;

    }

  }

  do {

    lVar5 = lVar6;

    if (plVar2 == (longlong *)0x0) break;

    lVar5 = (**(code **)(*plVar2 + 0x20))(plVar2);

    if (lVar5 != 0) {

      lVar5 = (**(code **)(*plVar2 + 0x20))(plVar2);

      break;

    }

    plVar2 = (longlong *)plVar2[3];

  } while( true );

  if (lVar4 != lVar5) {

    FID_conflict__assert

              (L"node->GetDocument() == 0 || node->GetDocument() == this->GetDocument()",

               L"C:\\dev\\tinyxml\\tinyxml.cpp",0xbd);

  }

  goto LAB_140025210;

  while (param_1 = (longlong *)param_1[3], param_1 != (longlong *)0x0) {

LAB_140025267:

    lVar4 = (**(code **)(*param_1 + 0x20))(param_1);

    if (lVar4 != 0) {

      lVar6 = (**(code **)(*param_1 + 0x20))(param_1);

      break;

    }

  }

  puVar3 = PTR_s_Error_when_TiXmlDocument_added_t_14039a428;

  if (*(char *)(lVar6 + 0x68) == '\0') {

    lVar4 = -1;

    *(undefined1 *)(lVar6 + 0x68) = 1;

    *(undefined4 *)(lVar6 + 0x6c) = 0xf;

    do {

      lVar4 = lVar4 + 1;

    } while (puVar3[lVar4] != '\0');

    FUN_140027f50(lVar6 + 0x70);

    *(undefined8 *)(lVar6 + 0x94) = 0xffffffffffffffff;

  }

  goto LAB_1400252ce;

}




