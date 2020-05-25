object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Lab5V1 (by Nemkovich)'
  ClientHeight = 338
  ClientWidth = 441
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 405
    Height = 16
    Caption = 
      #1054#1088#1075#1072#1085#1080#1079#1072#1094#1080#1103' '#1076#1074#1091#1085#1072#1087#1088#1072#1074#1083#1077#1085#1085#1086#1075#1086' '#1089#1087#1080#1089#1082#1072' '#1074' '#1074#1080#1076#1077' '#1086#1095#1077#1088#1077#1076#1080' ( Lab 5, v 1 ' +
      ')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 224
    Width = 113
    Height = 15
    Caption = '.== Individual task ==.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object ListBox1: TListBox
    Left = 127
    Top = 30
    Width = 306
    Height = 302
    ItemHeight = 13
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 8
    Top = 30
    Width = 113
    Height = 21
    TabOrder = 1
    TextHint = 'Number'
  end
  object Button1: TButton
    Left = 8
    Top = 57
    Width = 113
    Height = 25
    Caption = 'Add number'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 307
    Width = 113
    Height = 25
    Caption = 'Exit'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 245
    Width = 113
    Height = 25
    Caption = 'Random numbers'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 276
    Width = 113
    Height = 25
    Caption = 'Search min element'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button6: TButton
    Left = 8
    Top = 88
    Width = 113
    Height = 25
    Caption = 'Delete head'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 150
    Width = 113
    Height = 25
    Caption = 'Delete queue'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 181
    Width = 113
    Height = 25
    Caption = 'Check empty'
    TabOrder = 8
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 119
    Width = 113
    Height = 25
    Caption = 'Delete tail'
    TabOrder = 9
    OnClick = Button9Click
  end
end
