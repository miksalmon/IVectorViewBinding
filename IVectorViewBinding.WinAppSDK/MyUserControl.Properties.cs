﻿using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IVectorViewBinding
{
    public partial class MyUserControl
    {
        public static readonly DependencyProperty MyCollectionProperty =
            DependencyProperty.Register(
                nameof(MyCollection),
                typeof(IReadOnlyList<object>),
                typeof(MyUserControl),
                new PropertyMetadata(null, (dp, e) => ((MyUserControl)dp).OnMyCollectionChanged((IReadOnlyList<object>)e.NewValue)));

        public IReadOnlyList<object> MyCollection
        {
            get => (IReadOnlyList<object>)GetValue(MyCollectionProperty);
            set => SetValue(MyCollectionProperty, value);
        }

        private void OnMyCollectionChanged(IReadOnlyList<object> value)
        {

        }
    }
}
