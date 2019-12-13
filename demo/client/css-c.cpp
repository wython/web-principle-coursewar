// 四个哈希表
CompactRuleMap m_idRules;
CompactRuleMap m_classRules;
CompactRuleMap m_tagRules;
CompactRuleMap m_shadowPseudoElementRules;


// attach render tree ---> layoutTree
void ContainerNode::attachLayoutTree(const AttachContext& context) {
  for (Node* child = firstChild(); child; child = child->nextSibling()) {
    if (child->needsAttach())
      child->attachLayoutTree(childrenContext);
  }
}

/** 关联哈希表 */
//如果结点有id属性
if (element.hasID()) 
  collectMatchingRulesForList(
      matchRequest.ruleSet->idRules(element.idForStyleResolution()),
      cascadeOrder, matchRequest);
//如果结点有class属性
if (element.isStyledElement() && element.hasClass()) { 
  for (size_t i = 0; i < element.classNames().size(); ++i)
    collectMatchingRulesForList(
        matchRequest.ruleSet->classRules(element.classNames()[i]),
        cascadeOrder, matchRequest);
}
//伪类的处理
...
//标签选择器处理
collectMatchingRulesForList(
    matchRequest.ruleSet->tagRules(element.localNameForSelectorMatching()),
    cascadeOrder, matchRequest);
//最后是通配符
...



// 
if (!checkOne(context, subResult))
  return SelectorFailsLocally;
if (context.selector->isLastInTagHistory()) { 
    return SelectorMatches;
}

// check one function
switch (selector.match()) { 
  case CSSSelector::Tag:
    return matchesTagName(element, selector.tagQName());
  case CSSSelector::Class:
    return element.hasClass() &&
           element.classNames().contains(selector.value());
  case CSSSelector::Id:
    return element.hasID() &&
           element.idForStyleResolution() == selector.value();
}


// match
switch (relation) { 
  case CSSSelector::Descendant:
    for (nextContext.element = parentElement(context); nextContext.element;
         nextContext.element = parentElement(nextContext)) { 
      MatchStatus match = matchSelector(nextContext, result);
      if (match == SelectorMatches || match == SelectorFailsCompletely)
        return match;
      if (nextSelectorExceedsScope(nextContext))
        return SelectorFailsCompletely;
    } 
    return SelectorFailsCompletely;
      case CSSSelector::Child:
    //...
}