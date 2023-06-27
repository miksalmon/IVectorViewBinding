using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Collections.Specialized;
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
                new PropertyMetadata(null));

        public IReadOnlyList<object> MyCollection
        {
            get => (IReadOnlyList<object>)GetValue(MyCollectionProperty);
            set => SetValue(MyCollectionProperty, value);
        }
    }
}
